#pragma once
#include <vector>
#include <set>


namespace AOIService
{
	class AOIService;
	class IAOINode
	{
	public:
		IAOINode() {}
		virtual ~IAOINode() {}

	public:
		virtual void setService(AOIService* service) = 0;

		virtual int positionX() = 0;
		virtual int positionY() = 0;

		virtual IAOINode* getXForwardNode() = 0;
		virtual IAOINode* getYForwardNode() = 0;
		virtual IAOINode* getXBackwardNode() = 0;
		virtual IAOINode* getYBackwardNode() = 0;

		virtual void setXForwardNode(IAOINode* node) = 0;
		virtual void setYForwardNode(IAOINode* node) = 0;
		virtual void setXBackwardNode(IAOINode* node) = 0;
		virtual void setYBackwardNode(IAOINode* node) = 0;

		virtual int getWatchRange() = 0;
		virtual void onMove() = 0;

		virtual bool isInRange(IAOINode* node, int range) = 0;

		virtual void onEnterAOI(IAOINode* node) = 0;
		virtual void onLeaveAOI(IAOINode* node) = 0;
	};

	typedef std::vector<IAOINode*> AOINodeVector;
	typedef std::set<IAOINode*> AOINodeSet;
}
