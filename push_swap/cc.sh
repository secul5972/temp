make
er_cnt=0
ins_cnt=0
for((i=1;i<=5;i++)); do
	for((j=1;j<=5;j++)); do
	    if [ ${i} -eq ${j} ]; then
			continue
    		fi
		for((k=1;k<=5;k++)); do
		    if [ ${i} -eq ${k} -o ${j} -eq ${k} ]; then
				continue
    			fi
			for((l=1;l<=5;l++)); do
			    if [ ${i} -eq ${l} -o ${j} -eq ${l} -o ${k} -eq ${l} ]; then
					continue
    				fi	
				for((m=1;m<=5;m++)); do
				    if [ ${i} -eq ${m} -o ${j} -eq ${m} -o ${k} -eq ${m} -o ${l} -eq ${m} ]; then
						continue
    					fi
					ARG=""$i" "$j" "$k" "$l" "$m"";
					if [ "KO" == "`./push_swap $ARG |./checker $ARG`" ]; then
						echo $ARG;
						er_cnt=$(($er_cnt+1));
					else
						CNT=" `./push_swap $ARG | wc -l`";
						if [ $CNT -gt 12 ]; then
							echo $ARG ":" $CNT
							ins_cnt=$((ins_cnt+1));
						fi
					fi
				done	
			done	
		done	
	done	
done
echo "Error" $er_cnt"/120"
echo "Many ins" $ins_cnt"/120"
make fclean
