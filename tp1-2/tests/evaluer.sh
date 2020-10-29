#!/bin/bash
############################################################################################
# TP1 - Géocoding inversé
# http://ericbeaudry.ca/INF3105/tp1/
# INF3105 - Structures de données et algorithmes
# UQAM - Département d'informatique
#
# Script d'évaluation
#
# Instructions:
# 1. Déposer ce script avec les fichiers test dans un répertoire distinct (ex: tests).
# 2. Compiler le valideur: g++ -o valideur valideur.cpp -O
# 3. a) Étudiants:  Se placer dans le répertoire (cd) contenant votre programme.
#    b) Correcteur: Se placer dans répertoire contenant les soumissions.
# 4. Lancer ce script. Exemple: ../tests/evaluer.sh
############################################################################################

echo "Évaluation du TP1 d'INF3105..."

# Répertoire contenant les fichiers tests
repertoire_tests=`dirname $0`
# Villes à tester
villes="4rues st-cesaire sherbrooke montreal"
#villes="4rues st-cesaire"

if [ `pwd` -ef $repertoire_tests ];
then
    echo "Ce script doit être dans un répertoire différent de celui contenant tp1."
    echo "Ce script a été arrêté pour ne pas écraser les fichiers *-req[0-9]+.txt !"
    exit -2;
fi

########### Détection du valideur de résultats #######
# Le valideur à utiliser
valideur="${repertoire_tests}/valideur"
if [ -x "${valideur}-`uname`-`uname -p`" ]
then
    valideur="${valideur}-`uname`-`uname -p`"
else
    if [ -x "${valideur}-`uname`" ]
    then
        valideur="${valideur}-`uname`"
    fi
fi
######################################################


# Détection si l'utilitaire time sous Linux est disponible (peut afficher 0.00)
echo "Détection de /usr/bin/time..."
/usr/bin/time -f %U echo 2>&1 > /dev/null
souslinux=$?

# Limiter le temps d'exécution et la quantite de mémoire
ulimit -t 3600 -v 2097152 -f 65536
echo "Limite de temps par test : `ulimit -t` secondes."
echo "Limite de mémoire par test : `ulimit -v` KiO."
echo "Limite de taille de fichier : `ulimit -f` KiO."


# Détection du CPU
if [ -e /proc/cpuinfo ] ; then
    cpuinfo=`grep "model name" /proc/cpuinfo | sort -u | cut -d ":" -f 2`
else
    cpuinfo="?"
fi

function Nettoyer
{
	echo "Nettoyage"
    # Au cas où «make clean» du Makefile soumis soit insuffisant.
    #make clean

    rm -f *.o* *.gch tp[1-3] *-req?+.txt
    # Au besoin, nettoyer les précédents fichiers logs.
    rm -f log*.txt
}


##### Fonction d'évaluation d'un TP ######
function EvaluerTP
{
    ## Forcer la recompilation.
    #rm -f tp1 *.o *.gch
    #make clean

    # Compiler si requis.
    make tp1

    if [ ! -x tp1 ]
	    then
	    echo " Erreur : le fichier tp1 n'existe pas ou n'est pas exécutable!"
	    return
    fi

    date2=`date +%Y%m%d_%H%M%S`
    logfile="log-${date2}.txt"

    echo "Évaluation des temps d'exécution de tp1 sur les jeux de tests."
    echo "Les résultats sont déposés dans $logfile."

	echo "Machine : " `hostname`
	echo "#Machine : " `hostname`  > $logfile
	echo "CPU :$cpuinfo" 
	echo "#CPU :$cpuinfo"  >> $logfile
	echo "Date début : ${date2}"
	echo "#Date début : ${date2}"  >> $logfile
	echo "Limite de `ulimit -t` secondes par test"
	echo "#Limite de `ulimit -t` secondes par test"  >> $logfile
    echo
    echo "#" >> $logfile

    # Pour statistiques : nombre de lignes de code...
    # echo "Taille des fichiers source :" >> ${logfile}
    # wc *.{c*,h*}  >> ${logfile}

    check1=`grep "__CLASSE_TABLEAU_H__" tableau.h | wc -l`

    taille=`wc *.{c*,h*} | grep total`
    sommaire="$check1\t$taille"
    
    echo -e "#Test\tRequêtes\tCPU\tMém\tNum\tRue\tNum+-2" >> $logfile
    echo -e "Test\tRequêtes\tCPU\tMém\tNum\tRue\tNum+-2"

    # Itérer sur tous les réseaux
    for ville in $villes;
    do
        fcarte="${repertoire_tests}/${ville}-carte.txt"
        freseau="${repertoire_tests}/${ville}-reseau.txt"

        # Lister les fichiers tests pour le réseau actuel
        tests="`cd $repertoire_tests && ls ${ville}-req[0-9].txt`"

        # Itérer sur tous les fichiers tests
        for test in $tests; do
            nbreqs=`cat $repertoire_tests/$test | wc -l`

            if [ $souslinux -eq 0 ]; then
                t=`(/usr/bin/time -f "%U\t%M" ./tp1 $fcarte $repertoire_tests/$test > ${test%.txt}+.txt) 2>&1 | tail -n 1`
            else
                t=`(time -p ./$tp1 $fcarte $repertoire_tests/$test > ${test%.txt}+.txt) 2>&1 | egrep user | cut -f 2 -d " "` 
            fi

          	#if( [ -e ${repertoire_tests}/${test%.txt}+.txt ] ); then
            #	diff -tibw ${test%.txt}+.txt ${repertoire_tests}/${test%.txt}+.txt 2>&1 > /dev/null
        		#if [ $? -eq 0 ]; then
        	  # 	verif="OK"
         		#else
         	   # 	verif="Different"
        	#	fi
           # else
            #    verif="?"
           # fi
            if ( [ -x ${valideur} ] && [ -e  ${test%.txt}+.txt ] )
            then
            verif=`$valideur ${test%.txt}+.txt ${repertoire_tests}/${test%.txt}+.txt | tail -n 1`
        else
            verif="?"
            fi

            echo -e "$test\t$nbreqs\t${t}\t${verif}"
            echo -e "$test\t$nbreqs\t${t}\t${verif}" >> $logfile
            sommaire="${sommaire}\t\t${t}\t${verif}"
        done

    done
}

# Lister les soumissions Oto
tps=`ls -1 | grep .tp_oto`
# Si aucun répertoire n'existe, essayer le répertoire courant (auto-évaluation).
if [ ! -n "$tps" ]; then
    tps="."
fi

# Génération de l'entête du rapport.
date=`date +%Y%m%d_%H%M%S`
echo "#Rapport de correction INF3105 / $programme" > "rapport-${date}.txt"
echo -e "#Date:\t${date}" >> "rapport-${date}.txt"
echo -e "#Machine :\t" `hostname` >> "rapport-${date}.txt"
echo -e "#CPU :\t$cpuinfo" >> "rapport-${date}.txt"
echo >> "rapport-${date}.txt"

# Génération des titres des colonnes.
echo -e -n "#\t\t\t\t\t\t" >> "rapport-${date}.txt"
for ville in ${villes};
do
    ville=${ville%-ville.txt}
    tests="`cd $repertoire_tests && ls ${ville}-req[0-9].txt`"
    for test in $tests;
    do
        echo -e -n "$test\t\t\t\t\t\t" >> "rapport-${date}.txt"
    done
done
echo >> "rapport-${date}.txt"

echo -e -n "#Soumission\tCheck1\tTaille sources" >> "rapport-${date}.txt"
for ville in ${villes};
do
    ville=${ville%-ville.txt}
    tests="`cd $repertoire_tests && ls ${ville}-req[0-9].txt`"
    for test in $tests;
    do
        echo -e -n "\t\tCPU\tMém\tNum\tRue\tNum+-2" >> "rapport-${date}.txt"
    done
done
echo >> "rapport-${date}.txt"

# Itération sur chaque soumission.
for tp in $tps; do
    sommaire=""
    echo "## CORRECTION : $tp"
    pushd $tp
    	EvaluerTP
#		Nettoyer
    popd
    #echo -e ">> ${sommaire}"
    echo -e "${tp}\t${sommaire}" >> "rapport-${date}.txt"
done

