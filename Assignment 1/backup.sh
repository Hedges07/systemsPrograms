
#!/bin/bash
targetDir="."
argv=($*)
if [ $# == 0 ]; then 
    echo "Please Enter: $0 [-t target-dir] <suffix-list...>"
fi

destDir=`date | tr -d " :"`

let "i = 0"

if [[ $1 == "-t" ]]; then
    if [ -d $2 ]; then 
        targetDir=$2
        let "i = 2"
    else 
        echo $2 is not a valid target directory
        exit 1
    fi
fi

cd $targetDir
mkdir $destDir

N=$(($#-$i))
extensions=${argv[@]:$i:$N}


for var in $@
do
names=$(find -name "*$var")
nameArr=($(echo "$names" | tr ' ' '\n'))
for ((i = 0; i<${#nameArr[@]}; i++)); do 
    list="${nameArr[i]}"
    listb=$(echo "${list:2}")
    cp $listb $destDir
    rm $listb
done
done

cd $destDir
tar -cf archive.tar *
