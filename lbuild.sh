#build project
#bach -c "cd Buildsl/"
bash -c "mkdir Buildsl"
bash -c "mkdir Buildsl/Debug"
bash -c "mkdir Buildsl/Release"
bash -c "mkdir Buildsl/Release/assets"
bash -c "mkdir Buildsl/Debug/assets"

bash -c "cp -r assets Buildsl/Debug/"
bash -c "cp -r assets Buildsl/Release/"

cd Buildsl/

echo "  "
echo " Start compile project render_3d *** "
echo " "

cmake ../ 

 #-B_builds -DCMAKE_BUILD_TYPE=Debug not work 
 

# stop the release command's 
# read -p "Press any key to resume ..."

echo " "
echo "****** cmake ok build ******"
echo " "

# was cmake --build .
cmake --build .


read -p "Press any key to resume ..."