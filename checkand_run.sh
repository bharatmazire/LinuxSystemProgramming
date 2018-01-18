#!/bin/sh

###
#
#       check_and_run.sh
#
#       script for checking perticular file
#       if perticular file is present then run
#       else wait for file till it come
#

main(){
        if [ "$#" -ne "2" ]
        then
                echo "it should be like <executable name> <file to execute> <dependent file>"
                exit
        fi
#       echo "file to run : "$1 " and file dependent : "$2
#       i=1
        while [ "1" ]
        do
#               v=`expr $i % 4`
#               echo "value of v : "$v
#               if [ "$v" -eq "0" ]
#               then
#                       k=`touch $2`
#                       k=`ls`
#                       echo $k
#               fi
                find_op=`find $2 2> error`
                k=`rm error`
#               echo "find output is : "$find_op
                if [ "$find_op" ]
                then
#                       echo "file found"
#                       echo "executing file " $1
                        date_tm=`date`
                        echo " ______ FILE FOUND at time $date_tm ________" >> logs
                        k=`air sandbox run $1 > success 2> failure`
                        k=`rm $find_op`
                        echo "Report of graph $1 at time $date_tm. \n PFA for the same." | mail -s "Report of Graph $1 execution status" -a"./success" -a"./failure" "bharat.mazire@exusia.com"
                        k=`rm success`
                        k=`rm failure`
                else
                        date_tm=`date`
                        echo "file not find at time $date_tm" >> logs
                fi
                sleep 20
#               i=`expr $i + 1`
        done
}

# by $1 we are acepting file name which we need to run
# by $2 we are accepting the file name for whcih we are waiting the execution of graph

main $1 $2
