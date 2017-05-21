#include "AOINode.h"
#include "AOIService.h"


namespace AOIService
{
	AOINode::AOINode()
		:_x(0)
		,_y(0)
		,_watch_range(0)
		,_x_forward_node(nullptr)
		,_y_forward_node(nullptr)
		,_x_backward_node(nullptr)
		,_y_backward_node(nullptr)
		,_service(nullptr)
	{
	}

	AOINode::~AOINode()
	{
	}

	void AOINode::setService(AOIService* service)
	{
		_service = service;
	}

	int AOINode::positionX()
	{
		return _x;
	}

	int AOINode::positionY()
	{
		return _y;
	}

	IAOINode* AOINode::getXForwardNode()
	{
		return _x_forward_node;
	}

	void AOINode::setXForwardNode(IAOINode* node)
	{
		_x_forward_node = node;
	}

	IAOINode* AOINode::getXBackwardNode()
	{
		return _x_backward_node;
	}

	void AOINode::setXBackwardNode(IAOINode* node)
	{
		_x_backward_node = node;
	}

	class IAOINode* AOINode::getYForwardNode()
	{
		return _y_forward_node;
	}

	void AOINode::setYForwardNode(IAOINode* node)
	{
		_y_forward_node = node;
	}

	IAOINode* AOINode::getYBackwardNode()
	{
		return _y_backward_node;
	}

	void AOINode::setYBackwardNode(IAOINode* node)
	{
		_y_backward_node = node;
	}

	int AOINode::getWatchRange()
	{
		return _watch_range;
	}

	void AOINode::setWatchRange(int range)
	{
		_watch_range = range;
	}

	void AOINode::onEnterAOI(IAOINode* node)
	{
		auto iter = _aoi_node_set.find(node);
		if (iter == _aoi_node_set.end())
		{
			_aoi_node_set.insert(node);
		}
	}

	void AOINode::onLeaveAOI(IAOINode* node)
	{
		auto iter = _aoi_node_set.find(node);
		if (iter != _aoi_node_set.end())
		{
			_aoi_node_set.erase(iter);
		}
	}

	void AOINode::onMove()
	{
		if (_service == nullptr) return;

		_service->updateAOI(this);
	}

	bool AOINode::isInRange(IAOINode* node, int range)
	{
		if (node == nullptr) return false;
		if (node->positionX() - positionX() < range && node->positionY() - positionY() < range)
		{
			return true;
		}

		return false;
	}
}
