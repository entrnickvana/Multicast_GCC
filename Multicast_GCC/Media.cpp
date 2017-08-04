
#include "Media.h"
#include "Packet.h"

Media::Media()
{
}

Media::Media(string mediaNameArg)
{

    this->mediaName = mediaNameArg;

}

void Media::packetize(unsigned int numberOfPackets)
{
    unsigned int i = 1;
	for(vector<Packet>::iterator itr = packetsOfMedia.begin(); itr != packetsOfMedia.end(); ++itr)
    {
		Packet nuPacket(this, i++);
    }

}