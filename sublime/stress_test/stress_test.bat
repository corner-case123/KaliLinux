@echo off
setlocal EnableDelayedExpansion

g++ generator.cpp -o gen
g++ fast_soln.cpp -o my
g++ brute_force.cpp -o brute

set count=0
set max_tests=1000

:loop
set /a count+=1

if !count! GTR !max_tests! (
    echo All !max_tests! test cases passed successfully!
    pause
    exit /b
)

gen > input.txt
my < input.txt > out1.txt
brute < input.txt > out2.txt
fc out1.txt out2.txt > nul

if errorlevel 1 (
    echo Test case !count! FAILED!
    echo === Test case ===
    type input.txt
    echo === My Output ===
    type out1.txt
    echo === Brute Output ===
    type out2.txt
    pause
    exit /b
)

echo Test case !count! passed
goto loop
