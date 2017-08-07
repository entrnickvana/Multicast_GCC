
#include "Packet.h"
#include<string>
#include<vector>
#include "Media.h"



using namespace std;


Packet::Packet()
{

}

Packet::Packet(Media* parentMediaArg, unsigned int packetPartitionNumber, unsigned int sizeInBytes_)
{
   this->sizeInBytes = sizeInBytes_;
   this->parentMedia = parentMediaArg;
   string temp(to_string(packetPartitionNumber));
   this->packetName = "" + parentMediaArg->mediaName + temp;
   
}

bool Packet::operator<(const Packet & rhs) const
{
	return this->packetName.compare(rhs.packetName) < 0;
}


string Packet::toString()
{
    return packetName;
}

Packet::~Packet()
{
}
