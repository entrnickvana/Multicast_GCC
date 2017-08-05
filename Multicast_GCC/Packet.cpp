
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

bool Packet::operator<(const Packet& l) const
{
	if((int)l.packetName.at(0) < (int)this->packetName.at(0))
    {
        return false;
    }else
    {
        return true;
    }

    if( l.packetName.at(1) < this->packetName.at(1) )
    {
        return false;
    }else
    {
		return true;
    }

    return false;
	
}

string Packet::toString()
{
    return packetName;
}

Packet::~Packet()
{
}
