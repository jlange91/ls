#/bin/bash

nb_files=$1
i=$2

tput civis
printf "\r"
printf "\033[37;1m"
var=`echo "scale=2; ($i / $nb_files) * 100" | bc`
purcent=`echo "$var" | cut -d . -f 1`
printf $purcent
printf "%% "
printf "\033[42m"
j=0
int=`echo "$var / 4" | bc | cut -d . -f 1`
while [ $j != $int ]
do
	printf " "
	j=$((j+1))
done
printf "\033[0m"
