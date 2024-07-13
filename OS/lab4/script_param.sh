DISC="nvme0n1"
param="read_expire"
echo mq-deadline > /sys/block/$DISC/queue/scheduler
for i in {1..10}; do
	for value in 300 400 500; do
    		echo "$value" > /sys/block/$DISC/queue/iosched/$param
    		sync && /sbin/hdparm -tT /dev/$DISC | grep -Eo '[0-9]+\.[0-9]+ MB/sec' >> log$param$value.txt
	done
done

