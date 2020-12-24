b=$(<build)
v=$((b + 1))
echo $v > build

echo "start" > builds/$v
echo "EASY\n" >> builds/$v && \
./pathfinder test/easy >> builds/$v && \
echo "\nEMPTY\n" >> builds/$v && \
./pathfinder test/empty >> builds/$v && \
echo "\nEXAMPLE1\n" >> builds/$v && \
./pathfinder test/example1 >> builds/$v
echo "\nEXAMPLE2\n" >> builds/$v && \
./pathfinder test/example2 >> builds/$v
echo "\nMEDIUM\n" >> builds/$v && \
./pathfinder test/medium >> builds/$v && \
echo "\nHARD\n" >> builds/$v && \
./pathfinder test/hard >> builds/$v && \
echo "\nHARDEST\n" >> builds/$v && \
./pathfinder test/hardest >> builds/$v && \
echo "\nINVALID1\n" >> builds/$v
./pathfinder test/invalid1 >> builds/$v
echo "\nINVALID2\n" >> builds/$v
./pathfinder test/invalid2 >> builds/$v
echo "\nINVALID3\n" >> builds/$v
./pathfinder test/invalid3 >> builds/$v
echo "\nINVALID4\n" >> builds/$v
./pathfinder test/invalid4 >> builds/$v
echo "\nNOFILE\n" >> builds/$v
./pathfinder nofile >> builds/$v
echo "\nUSAGE\n" >> builds/$v
./pathfinder >> builds/$v
echo "end" >> builds/$v

diff builds/$b builds/$v
