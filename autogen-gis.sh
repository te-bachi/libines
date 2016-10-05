#!/bin/sh

dir=`echo "$0" | sed 's,[^/]*$,,'`
test "x${dir}" = "x" && dir='.'

if test "x`cd "${dir}" 2>/dev/null && pwd`" != "x`pwd`"
then
    echo "This script must be executed directly from the source directory."
    exit 1
fi

do_replace() {
    cd config
    echo " o dependency quirk"
    sed s/\-xM$/-xM1/g depcomp > depcomp.tmp
    mv depcomp.tmp depcomp
    cd ..
}

do_generate() {
    echo " o libtoolize"
    libtoolize --copy --force --automake
    echo " o aclocal"
    aclocal --force -I .
    echo " o autoheader"
    autoheader --force
    echo " o autoconf"
    autoconf --force
    echo " o automake"
    automake --add-missing --copy --force-missing --foreign
    # do_replace
}

do_regenerate() {
    echo " o automake"
    automake --add-missing --copy --force-missing --foreign
    do_replace
    cd build
    ./config.status
}

do_config() {
    cd build
    ../configure --enable-dependency-tracking --with-debug=yes --enable-static=yes --enable-shared=no --prefix=$GIS_LIBJAM
}

case $1 in
    all)
        do_generate
        do_config
        ;;
        
    make)
        do_regenerate
        ;;
        
    config)
        do_config
        ;;
        
    *)
        echo "autogen.sh [ all | config | make ]"
        ;;
esac
