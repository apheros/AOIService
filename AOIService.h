#pragma once
#include"IAOINode.h"


namespace AOIService
{
	class IAOINode;

	class AOIService
	{
	public:
		AOIService();
		~AOIService();

	public:
		void addNode(IAOINode* node);
		void removeNode(IAOINode* node);
		void updateAOI(IAOINode* node);
		void listNodeInRange(AOINodeVector& node_vect, IAOINode* center_node, int range);

	private:
		IAOINode* _x_root;
		IAOINode* _y_root;
	};
}
