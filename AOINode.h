#pragma once
#include "IAOINode.h"


namespace AOIService
{
	class AOIService;
	class AOINode : public IAOINode
	{
	public:
		AOINode();
		~AOINode();

	public:
		virtual void setService(AOIService* service);

		virtual int positionX();
		virtual int positionY();

		virtual IAOINode* getXForwardNode();
		virtual IAOINode* getYForwardNode();
		virtual IAOINode* getXBackwardNode();
		virtual IAOINode* getYBackwardNode();
		
		virtual void setXForwardNode(IAOINode* node);
		virtual void setYForwardNode(IAOINode* node);
		virtual void setXBackwardNode(IAOINode* node);
		virtual void setYBackwardNode(IAOINode* node);

		virtual int getWatchRange();
		virtual void setWatchRange(int range);
		virtual void onMove();
		virtual bool isInRange(IAOINode* node, int range);

		virtual void onEnterAOI(IAOINode* node);
		virtual void onLeaveAOI(IAOINode* node);

	private:
		int _x;
		int _y;

		int _watch_range;

		IAOINode* _x_forward_node;
		IAOINode* _y_forward_node;
		IAOINode* _x_backward_node;
		IAOINode* _y_backward_node;

		AOIService* _service;

		AOINodeSet _aoi_node_set;
	};
}


