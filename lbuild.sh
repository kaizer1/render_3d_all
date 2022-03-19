# build all files 

cd Buildsl/

echo "  "
echo " Start compile project render_3d *** "
echo " "

cmake ../

echo " "
echo "****** cmake ok build ******"
echo " "

# was cmake --build .
cmake --build .

read -p "Press any key to resume ..."