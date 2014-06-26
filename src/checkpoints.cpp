// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2014 NobleCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (     0, uint256("0xdbf8ee8b91b5f03d7786cb1d58f2588538b2d48d8c23a7913db5aac7bb58c481"))
			(	100, uint256("0x000cedc00442c5ecb96ec2f3d81e5513c59ec31f82cdfda95d939fab5f1a7696"))
			(	150, uint256("0xc977085510cb7256d7a7b96acfe851ee34f7dba91170b102ff80e0526ec2441a"))
			(	10000, uint256("0x621cb4ceab38c59da38cfe59c5e9547f0bbf324c374de8111fc6a15f31a39452"))
			(	50000, uint256("0xe8358688715339d51e0450bd1e9e3749bd940b31d4fc90b9eaf4530b2c8ffb9b"))		
			(	100000, uint256("0xdaa983f98f6cf60f98dcd3151fe82b16f7825fecc657f0c29e13ac62d0351e81"))
			(	140000, uint256("0x8b525c5c5ac84021d5aae16b8d85a3977a91461c157733423de756fe32ce1637"))
			(	170000, uint256("0x8fd23e16bc80406154df4cf083ba35fe53d876a3ead261af86f8cfbaef344919"))
			(	219718, uint256("0x0e1dd6ee774d8f30594fa40ce550e4a938449726b1d326471d7ea47c73d6c4e0"))
			;

		
    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;
	
        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
		
        return NULL;
    }
}
