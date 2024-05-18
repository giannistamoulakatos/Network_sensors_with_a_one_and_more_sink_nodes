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

#include "node.h"
Define_Module(Node);

connection listnodeAv[1000];
void Node::initialize()
{
    nodes_project = par("nodes_project");
    sinkIndex = par("sinkIndex");
    for (int i=0;i<nodes_project;i++)
    {
         if(getIndex()!=sinkIndex)
         {
            tTransmit=uniform(1,10);
            scheduleAt(simTime()+tTransmit,new cMessage("Hey Sink Node"));
            AverageLodefunction();
        }
    }

}
void Node::handleMessage(cMessage *msg)
{
    std::cout << "Node " << getIndex() << " received from: " << msg->getName() << " at time " << simTime() << std::endl;
    double result = AverageLodefunction();
    std::cout<<"Average Load "<< result <<std::endl;
    delete msg;
}

double Node::AverageLodefunction()
{
    double con=0;
    double resultAverageLoad=0;
    for(int i=0;i<nodes_project;i++)
    {
        resultAverageLoad+=listnodeAv[i].con;
    }
    return resultAverageLoad/double(nodes_project);
}


