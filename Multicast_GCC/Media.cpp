
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
	this->mediaSizeInBytes = mediaSizeInBytes_;
    this->packetize(numberOfPackets);
	

}

void Media::packetize(unsigned int numberOfPackets)
{
	/*  ////  DEBUG ONLY  ////////
	Packet* temp1;
	Packet* temp2;
	*/

	for(unsigned int i = 0; i < numberOfPackets; i++)
    {
		Packet nuPacket(this, i+1, this->mediaSizeInBytes/numberOfPackets);
        this->addPacket(nuPacket);
		this->setOfPackets.insert(nuPacket);
		
		/*  /////////////  DEBUG ONLY  /////////////////
			temp1 = &nuPacket;
			temp2 = this->packetsOfMedia.begin()._Ptr;
		*/
    }

	

}

bool Media::operator<(const Media& rhs) const
{
	return this->mediaName.compare(rhs.mediaName) < 0;
}

bool Media::operator==(const Media & rhs) const
{
	return this->mediaName.compare(rhs.mediaName) < 0;
}

void Media::addPacket(Packet packetToAdd)
{
    this->packetsOfMedia.push_back(packetToAdd);
}