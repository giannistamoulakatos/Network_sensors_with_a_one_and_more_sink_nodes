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
#include <random>
Define_Module(Node);

int nodes_project;
int tTransmit;
int sinkIndex;
int bsinkIndex;
void Node::initialize()
{
    nodes_project = par("nodes_project");
    srand(time(NULL));
    sinkIndex = par("sinkIndex");
    bsinkIndex = par("bsinkIndex");
    for (int i=0;i<nodes_project;i++)
    {
         if(getIndex()!=sinkIndex && getIndex()!=bsinkIndex)
         {
            tTransmit=uniform(1,10);
            scheduleAt(simTime()+tTransmit,new cMessage("Hey Sink Node"));
        }
    }

}
void Node::handleMessage(cMessage *msg)
{
    std::cout << "Node " << getIndex() << " received from: " << msg->getName() << " at time " << simTime() << std::endl;
    delete msg;
}
