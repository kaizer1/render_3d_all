#build project
#bach -c "cd Buildsl/"
bash -c "mkdir Buildsl/Debug"
bash -c "mkdir Buildsl/Debug/assets"

bash -c "cp -r assets Buildsl/Debug/"

cd Buildsl/

#bash -c "pwd"
echo "my files reading this "
#bash -c "cmake ../"
cmake ../


# stop the release command's 
# read -p "Press any key to resume ..."

echo " "
echo "****** cmake ok build ******"
echo " "

cmake --build .


read -p "Press any key to resume ..."