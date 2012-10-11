cd ~/svn/nocopy/users/Dak/
svn rm libnnal
svn commit -m "libnnal"
cp -r ~/libnnal ./
svn add libnnal
svn commit -m "libnnal"
