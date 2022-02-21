#!/bin/bash

fileName=$1
fileNameUp=${fileName^^}
fileNameC=src/${fileName}.cpp
fileNameH=inc/${fileName}.h

cat <<EOF > ${fileNameC}
#include "../${fileNameH}"

${fileName}::${fileName}() {}

${fileName}::~${fileName}() {}
EOF

cat <<EOF > ${fileNameH}
#ifndef ${fileNameUp}_H
#define ${fileNameUp}_H

class ${fileName}
{
    public:
        ${fileName}();
        ~${fileName}();
};

#endif  //${fileNameUp}_H
EOF