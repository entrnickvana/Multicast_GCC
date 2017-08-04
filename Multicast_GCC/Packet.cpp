
#include "Packet.h"
#include<string>
#include<vector>
#include "Media.h"



using namespace std;


Packet::Packet()
{

}

Packet::Packet(Media* parentMediaArg, unsigned int packetPartitionNumber)
{
   this->parentMedia = parentMediaArg;
   string temp(to_string(packetPartitionNumber));
   this->packetName = "" + parentMediaArg->mediaName + temp;
   
}

string Packet::toString()
{
    return packetName;
}

Packet::~Packet()
{
}
