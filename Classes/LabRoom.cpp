#include "LabRoom.h"

USING_NS_CC;



CCScene* LabRoom::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	LabRoom *layer = LabRoom::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool LabRoom::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	CCSize _screen = CCDirector::sharedDirector()->getWinSize();

	//create some drawing points to be displayed on screen
	//NW to NE
	LinePointJames line1;
	line1.start = CCPoint(0, _screen.height*0.5);
	line1.end = CCPoint(_screen.width, _screen.height*0.5);
	//changing to red
	line1.r = 1.0f;
	line1.a = 1.0f;

	//N to S
	LinePointJames line2;
	line2.start = CCPoint(_screen.width  * 0.5, 0);
	line2.end = CCPoint(_screen.width *0.5, _screen.height);
	line2.r = 1.0f;
	line2.a = 1.0f;



	//add lines to vector to be drawn
	drawingPoints.push_back(line1);
	drawingPoints.push_back(line2);


	//draw blue box 
	//4 lines at quater quadrands of the screen
	//top left to top right
	LinePointJames blueboxTLTR;
	blueboxTLTR.start = CCPoint(_screen.width *0.25, _screen.height * 0.25);
	blueboxTLTR.end = CCPoint(_screen.width *0.75, _screen.height * 0.25);
	blueboxTLTR.b = 1.0f;
	blueboxTLTR.a = 1.0f;

	//top right to bottom right
	LinePointJames blueboxTRBR;
	blueboxTRBR.start = CCPoint(_screen.width *0.75, _screen.height * 0.25);
	blueboxTRBR.end = CCPoint(_screen.width *0.75, _screen.height * 0.75);
	blueboxTRBR.b = 1.0f;
	blueboxTRBR.a = 1.0f;

	//bottom right to bottom left
	LinePointJames blueboxBRBL;
	blueboxBRBL.start = CCPoint(_screen.width *0.75, _screen.height * 0.75);
	blueboxBRBL.end = CCPoint(_screen.width *0.25, _screen.height * 0.75);
	blueboxBRBL.b = 1.0f;
	blueboxBRBL.a = 1.0f;

	//bottom left to top left
	LinePointJames blueboxBLTL;
	blueboxBLTL.start = CCPoint(_screen.width *0.25, _screen.height * 0.75);
	blueboxBLTL.end = CCPoint(_screen.width *0.25, _screen.height * 0.25);
	blueboxBLTL.b = 1.0f;
	blueboxBLTL.a = 1.0f;

	drawingPoints.push_back(blueboxTLTR);
	drawingPoints.push_back(blueboxTRBR);
	drawingPoints.push_back(blueboxBRBL);
	drawingPoints.push_back(blueboxBLTL);
	glLineWidth(10);
	/*for (int i = 0; i < drawingPoints.size(); i++)
	{
		DrawPrimitives::setDrawColor4F(drawingPoints.at(i).r, drawingPoints.at(i).g, drawingPoints.at(i).b, drawingPoints.at(i).a);
		DrawPrimitives::drawLine(drawingPoints.at(i).start, drawingPoints.at(i).end);
	}*/

	return true;
}

/*void LabRoom::draw(Renderer* renderer, const kmMat4& transform, bool transformUpdated)
{


	for (int i = 0; i < drawingPoints.size(); i++)
	{
		ccDrawColor4F(drawingPoints.at(i).r, drawingPoints.at(i).g, drawingPoints.at(i).b, drawingPoints.at(i).a);
		ccDrawLine(drawingPoints.at(i).start, drawingPoints.at(i).end);
	}

}*/


/*void LabRoom::draw(Renderer *renderer, const kmMat4& transform, bool transformUpdated)
{
	_customCommand.init(_globalZOrder + 10);
	_customCommand.func = CC_CALLBACK_0(LabRoom::onDraw, this, transform, transformUpdated);
	renderer->addCommand(&_customCommand);
}*/
/*void LabRoom::onDraw(const kmMat4 &transform, bool transformUpdated)
{
	for (int i = 0; i < drawingPoints.size(); i++)
	{
		ccDrawColor4F(drawingPoints.at(i).r, drawingPoints.at(i).g, drawingPoints.at(i).b, drawingPoints.at(i).a);
		ccDrawLine(drawingPoints.at(i).start, drawingPoints.at(i).end);
	}
}*/

void LabRoom::onDrawPrimitives(const kmMat4 &transform, bool transformUpdated)
{
	kmGLPushMatrix();
	kmGLLoadMatrix(&transform);
	DrawPrimitives::setDrawColor4F(Color4F::BLUE.r, Color4F::BLUE.g, Color4F::BLUE.b, Color4F::BLUE.a );
	//add your primitive drawing code here
	DrawPrimitives::drawLine(ccp(0, 0), ccp(100, 100));
}

void LabRoom::draw(Renderer *renderer, const kmMat4& transform, bool transformUpdated)
{
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(LabRoom::onDrawPrimitives, this, transform, transformUpdated);
	renderer->addCommand(&_customCommand);
}