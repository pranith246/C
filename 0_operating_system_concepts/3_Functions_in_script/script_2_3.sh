echo "Enter number of elements in array:"
read n

echo "Enter elements :"
for i in `seq 1 $n`
do
read arr[$i]
done

echo "sorting..."
for i in `seq 1 $n`
do
	for j in `seq 1 $n`
	do
		if [ ${arr[$i]} -lt ${arr[$j]} ]
		then		
			#echo ${arr[$i]} is greater than ${arr[$j]}
			temp=${arr[$j]}
			arr[$j]=${arr[$i]}
			arr[$i]=$temp
		fi
	done
#echo ${arr[$i]}
done


echo "Sorted order is: "
for i in `seq 1 $n`
do
	echo ${arr[$i]}
done

#for i in 1 2 3 4 5
#do
#	echo `expr $i + 1`
#done

