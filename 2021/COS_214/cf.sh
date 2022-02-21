#!/bin/bash

########################################################################################
#
# USAGE: ./cf.sh fileOne fileTwo fileThree
#
#######################################################################################

cppDir=src/ # The directory with the .cpp files, with ending '/'. (If all in same directory leave as '.')
incDir=inc/ # The directory with the .h files, with ending '/'. (If all in same directory leave as '.')
# NOTE: If no other directories and you have the above 2 lines equal to '.', then you should change line 18 from #include "../${fileNameH}" to #include "${fileNameH}"

mkdir -p ${cppDir} ${incDir};

for fileName in "$@"
do
fileNameUp=${fileName^^}
fileNameC=${cppDir}
fileNameC+=${fileName}.cpp
fileNameH=${incDir}
fileNameH+=${fileName}.h

cat <<EOF > ${fileNameC}
#include "../${fileNameH}"

${fileName}::${fileName}() {}

${fileName}::~${fileName}() {}
EOF

cat <<EOF > ${fileNameH}
/****************************************************************************************************
 *  @file ${fileNameH}
 *  @brief The header file for the ${fileName} class.
 ***************************************************************************************************/

#ifndef ${fileNameUp}_H
#define ${fileNameUp}_H

/****************************************************************************************************
 *  @class ${fileName}
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class ${fileName}
{
    public:
        /**
         *  @fn ${fileName}()
         *  @brief The constructor for the class.
         */
        ${fileName}();

        /**
         *  @fn ~${fileName}()
         *  @brief The destructor for the class.
         */
        ~${fileName}();
};

#endif  //${fileNameUp}_H
EOF
done