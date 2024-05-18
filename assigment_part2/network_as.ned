//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 



network Network_as
{
   parameters:
        int nodes_project=default(1000);
        double rc=default(0.5);
        double connection_node=default(1);//possibility
        int sinkIndex=default(0);
        @display("bgb=1000,1000");
    submodules:
        node[nodes_project]:Node
        {
            xPos=intuniform(0,20);
            yPos=intuniform(0,20);
            @display("bgb=$xPos,$yPos");           
        }   
     
    
    connections:
        for i=0..nodes_project-1,for j=i+1..nodes_project-1
        {
            node[i].gates_node++ <--> node[j].gates_node++ if i!=j && sqrt((node[i].xPos-node[j].xPos)^2+(node[i].yPos-node[j].yPos)^2)<rc;
        }		
}    	

         


