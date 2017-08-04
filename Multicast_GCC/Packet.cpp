
#include "Packet.h"
#include<string>
#include<vector>
#include "Media.h"
//#include "catalogFile.h"


using namespace std;


Packet::Packet()
{

}

Packet::Packet(Media* parentMediaArg, unsigned int packetPartitionNumber)
{
   parentMedia = parentMediaArg;

}

string Packet::toString()
{
    return packetName;
}

Packet::~Packet()
{
}
