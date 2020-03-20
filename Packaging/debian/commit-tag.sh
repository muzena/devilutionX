#!/bin/bash
set -e
### https://developer.github.com/v3/#rate-limiting
### https://developer.github.com/v3/git/tags/#get-a-tag

#cd ..
#sed -i 's#git describe --abbrev=0 --tags#sed q ./debian/tag.txt#g' ./CMake/git.cmake
#wait $!
#sed -i 's#git log -1 --format=-%h#sed q ./debian/commit.txt#g' ./CMake/git.cmake
#wait $!
#cd ./debian
echo "-" > ./debian/commit.txt
# Latest commit
curl -s  https://api.github.com/repos/diasurgical/devilutionX/git/refs/heads/master | jshon -e object | jshon -e sha -u | cut -c1-8 >> ./debian/commit.txt
wait $!
sed -i -e :a -e '/$/N; s/\n//; ta' ./debian/commit.txt
wait $!
# Latest tag
curl -s -H "Accept: application/vnd.github.v3+json" https://api.github.com/repos/diasurgical/devilutionX/git/refs/tags | jq -r '.[0].ref' | awk '{sub(/^.{10}/,"")}1' > ./debian/tag.txt

