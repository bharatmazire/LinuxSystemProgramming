#!/bin/sh

#################################################
#                                               #
#       CALCULATOR FOR BASIC OPERATIONS         #
#                                               #
################################################


#*********** B A S I C  P A R T ************************************
add(){
        echo "addition"

        echo "enter val 1:"
        read  v1
        echo "enter val 2:"
        read  v2
        echo "addition is : "$(($v1 + $v2))
}
sub(){
        echo "subtraction"

        echo "enter val 1:"
        read v1
        echo "enter val 2:"
        read v2
        subtraction=`expr $v1 - $v2`
        echo "subtraction is : "$subtraction
}
mul(){
        echo "multiplication"

        echo "enter val 1:"
        read v1
        echo "enter val 2:"
        read v2
        let multi="$v1 * $v2"
        echo "multipliaction is : "$multi
}
div(){
        echo "division "

        echo "enter val 1:"
        read v1
        echo "enter val 2:"
        read v2
        division=`expr $v1 / $v2`
        echo "division is : "$division
}

basic_calci(){
        echo "Welcome BASIC Calculator"
        choice=0
        while [ "$choice" != "5" ]
        do
                echo "1.add 2.sub 3.mul 4.div 5.exit"
                read choice
                echo "choice is : "$choice

                case $choice
                in
                        1)      add;;
                        2)      sub;;
                        3)      mul;;
                        4)      div;;
                esac
        done
}

#**************************************************************************************************


#***************** S C I E N T I F I C   P A R T  **************************************************

sin(){
        echo "sin"
        echo "value and answer will come in term of degree"
        echo "enter value of degree"
        read value
        const=0.0174524064
        echo $value $const |awk '{print "sin value is : "$1 * $2}'
}

cos(){
        echo "cos"
        echo "sry dude its in progress !!!"
}

tan(){
        echo "tan"
        echo "value and answer will come in term of degree"
        echo "enter value of degree"
        read value
        const=0.0174550649
        echo $value $count | awk '{print "tan value is : "$1 * $2}'
}


log(){
        echo "log"
        echo "work in progress..."
}

scientific_calci(){
        echo "scientific_calci"
        choice=0
        while [ "$choice" != "5" ]
        do
                echo "1.sin 2.cos 3.tan 4.log 5.exit"
                read choice
                echo "choice is : "$choice
                case $choice
                in
                        1)    sin;;
                        2)    cos;;
                        3)    tan;;
                        4)    log;;
                esac
        done
}
#******************************************************************************************************************


#************ C O N V E R S I O N   P A R T  ************************************************************************

#_______ TEMP PART ________________
c_f(){
        echo "celcius to fara.."
        echo $1 | awk '{print "fara.. value is : "$1 * 1.8 + 32}'
}

f_c(){
        echo "fara.. to celcius"
        echo $1 | awk '{print "celcius value is : "($1 - 32) / 1.8}'

}

temp(){
        echo "temprature"
        choice=0
        while [ "$choice" != "3" ]
        do
                echo "1.c_to_f 2. f_to_c 3.exit"
                read choice
                if [ "$choice" -le "2" ]
                then
                        echo "enter temprature : "
                        read tmp
                        echo "temprature is : "$tmp
                fi
                case $choice
                in
                        1)c_f $tmp;;
                        2)f_c $tmp;;
                esac
        done
}
#_____________________________

#__________ LENGTH PART ______
m_to_m(){
        echo "meter to mile"
        echo $1 | awk '{print "mile is : "$1 * 0.006213689}'
}

m_to_y(){
        echo "meter to yard"
        echo $1 | awk '{print "yard is : "$1 * 1.0936132983}'
}

m_to_f(){
        echo "meter to foot"
        echo $1 | awk '{print "foot is : "$1 * 3.280839895}'
}

m_to_i(){
        echo "meter to inch"
        echo $1 | awk '{print "inch is : "$1 * 39.37007874}'
}


leng(){
        echo "length"
        choice=0
        while [ "$choice" != "5" ]
        do
                echo "1.meter to mile 2.meter to yard 3.meter to foot 4.meter to inch 5.exit"
                read choice
                if [ "$choice" -le "4" ]
                then
                        echo "enter value of meter : "
                        read met
                        echo "meter value is : "$met
                fi
                case $choice
                in
                        1)m_to_m $met;;
                        2)m_to_y $met;;
                        3)m_to_f $met;;
                        4)m_to_i $met;;
                esac
        done
}
#________________________________

#_________ FLUID PART ____________
l_to_m(){
        echo "liter to mili-liter"
        echo $1 | awk '{print "mili-liter : "$1 * 1000}'
}

l_to_g(){
        echo "liter to US gallon"
        echo $1 | awk '{print "gallon : "$1 * 0.2641721769}'
}

flud(){
        echo "fluid"
        choice=0
        while [ "$choice" != "3" ]
        do
                echo "1.liter to mili-liter 2.liter to gallon(U.S.) 3.exit"
                read choice
                if [ "$choice" -le "2" ]
                then
                        echo "enter value of liter : "
                        read ltr
                        echo "liter value is : "$ltr
                fi
                case $choice
                in
                        1)l_to_m $ltr;;
                        2)l_to_g $ltr;;
                esac
        done
}
#_______________________________

#___________ MASS PART _________
g_to_kg(){
        echo "gram to kilo gram"
        echo $1 | awk '{print "kilogram is : "$1 * 0.001}'
}

g_to_mg(){
        echo "gram to mili gram"
        echo $1 | awk '{print "mili gram is : "$1 * 1000}'
}

g_to_ton(){
        echo "gram to tone "
        echo $1 | awk '{print "tone value is : "$1 * 0.000001}'
}

g_to_pd(){
        echo "gram to pound"
        echo $1 | awk '{print "pound value is : "$1 * 0.0022046244}'
}

mass(){
        echo "mass"
        choice=0
        while [ "$choice" != "5" ]
        do
                echo "1.g to kg 2.g to mg 3.g to ton 4.g to pound 5.exit"
                read choice
                if [ "$choice" -le "4" ]
                then
                        echo "enter value of gram : "
                        read g
                        echo "gram value is : "$g
                fi
                case $choice
                in
                        1)g_to_kg $g;;
                        2)g_to_mg $g;;
                        3)g_to_ton $g;;
                        4)g_to_pd $g;;
                esac
        done
}
#_________________________________

#______ CURRENCY PART ___________
r_to_do(){
        echo "rs to dollar"
        echo $1 | awk '{print "Dollar : "$1 * 0.02}'
}

r_to_di(){
        echo "rs to dinar"
        echo $1 | awk '{print "Dinar : "$1 * 0.0059}'
}

r_to_p(){
        echo "rs to pound"
        echo $1 | awk '{print "Pound : "$1 * 0.012}'
}

r_to_y(){
        echo "rs to yen"
        echo $1 | awk '{print "Yen : "$1 * 1.78}'
}

r_to_b(){
        echo "rs to bitcoin"
        echo $1 | awk '{print "BitCoin : "$1 * 0.0000011}'
}


curr(){
        echo "currency : according to date 04/01/2018"
        choice=0
        while [ "$choice" != "6" ]
        do
                echo "1.Rs to Dollar 2.Rs to Dinar 3.Rs to Pound 4.Rs to Yen 5.Rs to Bitcoin 6.exit"
                read choice
                if [ "$choice" -le "5" ]
                then
                        echo "enter value of RS : "
                        read rs
                        echo "rupee : "$rs
                fi
                case $choice
                in
                        1)r_to_do $rs;;
                        2)r_to_di $rs;;
                        3)r_to_p $rs;;
                        4)r_to_y $rs;;
                        5)r_to_b $rs;;
                esac

        done
}
#_____________________________

conversion(){
        echo "Conversion"
        choice=0
        while [ "$choice" != "6" ]
        do
                echo "1.temprature 2.length 3.fluid 4.mass 5.currency 6.exit"
                read choice
                echo "your choice is : "$choice
                case $choice
                in
                        1)temp;;
                        2)leng;;
                        3)flud;;
                        4)mass;;
                        5)curr;;
                esac
        done
}
#***************************************************

main(){
        echo "Welcome to calculator "
        choice=0
        while [ "$choice" != "4" ]
        do
                echo "1.basic 2.scientific 3.conversion 4.exit"
                read choice
                echo "choice is : "$choice

                case $choice
                in
                        1) basic_calci;;
                        2) scientific_calci;;
                        3) conversion;;
                esac
        done
}

# execution start from here
main
