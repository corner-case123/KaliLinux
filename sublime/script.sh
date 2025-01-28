

for i in `seq 1 100`; do
    # prints the current test number
    # I like to do this so I can see progress is being made
    echo $i 

    ./tc_gen $i 7 7 > a.in
    # $i is for random seed 
    ./soln < a.in > a.out
    ./soln_naive < a.in > answer.txt

    diff a.out answer.txt || break
done
