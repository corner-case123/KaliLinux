@echo off
setlocal enabledelayedexpansion

:: Compile both programs
echo Compiling programs...
g++ -O2 input_generator.cpp -o gen.exe
if errorlevel 1 (
    echo Failed to compile input_generator.cpp
    pause
    exit /b 1
)

g++ -O2 code_to_benchmark.cpp -o bench.exe
if errorlevel 1 (
    echo Failed to compile code_to_benchmark.cpp
    pause
    exit /b 1
)

:: Number of runs
set RUNS=1000
set LIMIT=100000000

echo.
echo Starting benchmark with %RUNS% runs...
echo Run ^| Operations ^| Status
echo ---------------------------

for /l %%i in (1,1,%RUNS%) do (
    :: Generate inputs
    gen.exe > input.txt 2>nul
    if errorlevel 1 (
        echo %%i   ^| N/A     ^| ERROR: Input generation failed
        goto :error_exit
    )

    :: Run benchmark code and capture output
    bench.exe < input.txt > temp_output.txt 2>nul
    if errorlevel 1 (
        echo %%i   ^| N/A     ^| ERROR: Benchmark execution failed
        goto :error_exit
    )

    :: Get the last line from output (operation count)
    for /f "delims=" %%a in (temp_output.txt) do set "lastLine=%%a"

    :: Check if lastLine is a number
    echo !lastLine! | findstr /r "^[0-9][0-9]*$" >nul
    if errorlevel 1 (
        echo %%i   ^| !lastLine!     ^| ERROR: Invalid output format
        goto :error_exit
    ) else (
        set /a OPS=!lastLine!
        if !OPS! GTR %LIMIT% (
            echo %%i   ^| !OPS!     ^| FAILED: Limit Exceeded
            echo.
            echo ERROR: Operation count !OPS! exceeds limit of %LIMIT%
            echo Terminating benchmark process...
            goto :error_exit
        ) else (
            echo %%i   ^| !OPS!     ^| OK
        )
    )
)

echo.
echo All %RUNS% tests completed successfully!
goto :cleanup

:error_exit
echo.
echo Benchmark terminated due to error or limit exceeded.
goto :cleanup

:cleanup
:: Clean up temporary files
if exist temp_output.txt del temp_output.txt
if exist input.txt del input.txt

endlocal
pause
