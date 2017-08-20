
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
   this->partitionNumber = packetPartitionNumber;
   string temp(to_string(packetPartitionNumber));
   this->packetName = "" + parentMediaArg->mediaName + temp;
   
}

bool Packet::operator<(const Packet & rhs) const
{
	if (this->parentMedia->mediaName.compare(rhs.parentMedia->mediaName) < 0)
	{

		if (&this->parentMedia->mediaName == nullptr  || &rhs.parentMedia->mediaName == nullptr)
		{
			int temp = 1;
		}
		return true;
	}
	else
	{
		return this->partitionNumber < rhs.partitionNumber;
	}

}

bool Packet::operator>(const Packet & rhs) const
{

	return !(*this < rhs);
}

bool Packet::operator<=(const Packet & rhs) const
{
	return !(*this > rhs);
}

bool Packet::operator>=(const Packet & rhs) const
{
	return !(*this < rhs);
}

bool Packet::operator==(const Packet & rhs) const
{
	bool cond1 = this->packetName.compare(rhs.packetName) == 0;
	bool cond2 = this->parentMedia == rhs.parentMedia;

	return cond1 && cond2;
}

bool Packet::operator!=(const Packet & rhs) const
{
	return !(*this == rhs);
}

//Packet& Packet::operator=(const Packet & rhs)
//{
//
//	if (this != &rhs)
//	{
//		this->sizeInBits = rhs.sizeInBits;
//		this->sizeInBytes = rhs.sizeInBytes;
//		this->packetName = rhs.packetName;
//		this->data = rhs.data;
//		this->parentMedia = rhs.parentMedia;
//		this->partitionNumber = rhs.partitionNumber;
//
//	}
//	return *this;
//	// TODO: insert return statement here
//}


string Packet::toString()
{
    return packetName;
}



Packet::~Packet()
{
}
