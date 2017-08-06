
#include "Media.h"
#include "Packet.h"

Media::Media()
{
}

Media::Media(string mediaNameArg)
{

    this->mediaName = mediaNameArg;

}

Media::Media(string mediaNameArg, unsigned int numberOfPackets)
{

    this->mediaName = mediaNameArg;
    this->packetize(numberOfPackets);

}

void Media::packetize(unsigned int numberOfPackets)
{
    
	for(unsigned int i = 0; i < numberOfPackets + 1; i++)
    {
		Packet nuPacket(this, i);
        this->addPacket(nuPacket);
    }

}

bool Media::operator<(const Media& rhs) const
{
	return this->mediaName.compare(rhs.mediaName) < 0;
}

void Media::addPacket(Packet packetToAdd)
{
    this->packetsOfMedia.push_back(packetToAdd);
}