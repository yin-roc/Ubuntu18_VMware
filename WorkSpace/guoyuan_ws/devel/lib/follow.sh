gnome-terminal -x bash -c "cd ~/workingSpaceSet/guoyuan_ws ./devel/setup.bash;roslaunch f1tenth_simulator simulator.launch" 
sleep 3s
gnome-terminal -x bash -c "cd ~/workingSpaceSet/guoyuan_ws;source ./devel/setup.bash;rosrun tianracer_navigation Pure_Pursuit"
