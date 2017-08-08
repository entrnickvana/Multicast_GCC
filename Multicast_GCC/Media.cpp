
#include "Media.h"
#include "Packet.h"

Media::Media()
{
}

Media::Media(string mediaNameArg, unsigned int mediaSizeInBytes_)
{

    this->mediaName = mediaNameArg;
	this->mediaSizeInBytes = mediaSizeInBytes_;

}

Media::Media(string mediaNameArg, unsigned int numberOfPackets, unsigned int mediaSizeInBytes_)
{

    this->mediaName = mediaNameArg;
    this->packetize(numberOfPackets);
	this->mediaSizeInBytes = mediaSizeInBytes_;

}

void Media::packetize(unsigned int numberOfPackets)
{
    
	for(unsigned int i = 0; i < numberOfPackets + 1; i++)
    {
		Packet nuPacket(this, i+1, this->mediaSizeInBytes/numberOfPackets);
        this->addPacket(nuPacket);
    }

	this->setOfPackets.insert(packetsOfMedia.begin(), packetsOfMedia.end());

}

bool Media::operator<(const Media& rhs) const
{
	return this->mediaName.compare(rhs.mediaName) < 0;
}

void Media::addPacket(Packet packetToAdd)
{
    this->packetsOfMedia.push_back(packetToAdd);
}