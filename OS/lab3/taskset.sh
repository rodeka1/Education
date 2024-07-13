cd linpack
for C in {0..11}; do
    sudo LINPACK_ARRAY_SIZE=2048 taskset -c $C ./linpack | grep -Eo '[0-9]+\.[0-9]+$' >> logtaskset$C.txt
done	
