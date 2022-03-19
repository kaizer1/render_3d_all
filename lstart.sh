# start.sh 

if [[ -f "Buildsl/Debug/render_3d.exe" ]]
then
    echo "This file exists on your filesystem."

 cd Buildsl/Debug/
 bash -c "./render_3d.exe"

fi

#read -p "Press any key to resume ..."