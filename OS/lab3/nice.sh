cd linpack
for N in {-20..19}; do
    sudo nice -n $N ./linpack &
done
