run_prog(){
        i=1
        one=1
        sixty=60
        tf=24
        while [ "$i" -lt "3" ]
        do
        #       echo "loop start "$i" time"
                hh=`date +%H`
                mm=`date +%M`
        #       echo "HH :"$2" MM:"$3
        #       echo "hh :"$hh" mm:"$mm
                if [ "$2" -gt "$hh" ]
                then
                        if [ "$3" -gt "$mm" ]
                        then
                                f_h=`expr $2 - $hh`
                                f_m=`expr $3 - $mm`
                        else
                                f_h=`expr $2 - $hh - $one`
                                f_m=`expr $sixty - $mm + $3`
                        fi
                else
                        if [ "$2" -lt "$hh" ]
                        then
                                if [ "$3" -gt "$mm" ]
                                then
                                        f_h=`expr $tf - $hh + $2`

                                        f_m=`expr $3 - $mm`
                                else
                                        f_h=`expr $tf - $hh - $2 - $one`
                                        f_m=`expr $sixty - $mm + $3`
                                fi
                        else
                                if [ "$3" -gt "$mm" ]
                                then
                                        f_h=`expr $2 - $hh`
                                        f_m=`expr $3 - $mm`
                                else
                                        f_h=`expr $2 - $hh + $tf - $one`
                                        f_m=`expr $sixty - $mm + $3`
                                fi
                        fi
                fi
        #       echo "waiting time is : "
        #       echo "hr : "$f_h" mn: "$f_m
                wait_sec=`echo $f_h $f_m | awk '{print"",($1*60*60)+($2*60)}'`
        #       echo "Going to wait for "$wait_sec "sec."
                j=`sleep $wait_sec`
                j=`air sandbox run $1 > success 2> error`
                j=`echo "Report of Graph $1 execution " | mail -s "Report of $1 graph" -a"./success" -a"./error" "bharat.mazire@exusia.com"`
        #       echo "1 min break ;"
                j=`sleep 1m`

                i=`expr $i + 1`
        done

}


main(){
        if [ "$#" -ne "3" ]
        then
                echo "It should be <executable> <program> <hour 01,02,...,24> <minutes 01,02,..,60>"
        else
                run_prog $1 $2 $3
        fi
}

main $1 $2 $3
