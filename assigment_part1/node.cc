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
int sinkIndex1;
int sinkIndex2;
int sinkIndex3;
int sinkIndex4;
int sinkIndex5;
int sinkIndex6;
int sinkIndex7;
int sinkIndex8;
int sinkIndex9;
int sinkIndex10;
int sinkIndex11;
int sinkIndex12;
int sinkIndex13;
int sinkIndex14;
int sinkIndex15;
int sinkIndex16;
int sinkIndex17;
int sinkIndex18;
int bsinkIndex;
void Node::initialize()
{
    nodes_project = par("nodes_project");
    srand(time(NULL));
    sinkIndex = par("sinkIndex");
    sinkIndex1 = par("sinkIndex1");
    sinkIndex2 = par("sinkIndex2");
    sinkIndex3 = par("sinkIndex3");
    sinkIndex4 = par("sinkIndex4");
    sinkIndex5 = par("sinkIndex5");
    sinkIndex6 = par("sinkIndex6");
    sinkIndex7 = par("sinkIndex7");
    sinkIndex8 = par("sinkIndex8");
    sinkIndex9 = par("sinkIndex9");
    sinkIndex10 = par("sinkIndex10");
    sinkIndex11 = par("sinkIndex11");
    sinkIndex12 = par("sinkIndex12");
    sinkIndex13 = par("sinkIndex13");
    sinkIndex14 = par("sinkIndex14");
    sinkIndex15 = par("sinkIndex15");
    sinkIndex16 = par("sinkIndex16");
    sinkIndex17 = par("sinkIndex17");
    sinkIndex18 = par("sinkIndex18");
    bsinkIndex = par("bsinkIndex");
    for (int i=0;i<nodes_project;i++)
    {
         if(getIndex()!=sinkIndex && getIndex()!=sinkIndex1 && getIndex()!=sinkIndex2 && getIndex()!=sinkIndex3 && getIndex()!=sinkIndex4 && getIndex()!=sinkIndex5 && getIndex()!=sinkIndex6 && getIndex()!=sinkIndex7 && getIndex()!=sinkIndex8 && getIndex()!=sinkIndex9 && getIndex()!=sinkIndex10 && getIndex()!=sinkIndex11 && getIndex()!=sinkIndex12 && getIndex()!=sinkIndex13 && getIndex()!=sinkIndex14 && getIndex()!=sinkIndex15 && getIndex()!=sinkIndex16 && getIndex()!=sinkIndex17 && getIndex()!=sinkIndex18 && getIndex()!=bsinkIndex)
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
