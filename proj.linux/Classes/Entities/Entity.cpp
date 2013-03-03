#include "cocos2d.h"

class Entity
{
	private:
		CCSprite* mSprite;

		int mWidth;
		int mHeight;
		int mHorizontalFramesCount;
		int mVerticalFramesCount;

		int mCurrentFrameIndex;

		int* mFramesCoordinatesX;
		int* mFramesCoordinatesY;

	public:
		Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount)
		{
			this->mSprite = CCSprite::create(pszFileName);

			this->mWidth  = this->mSprite->getTextureRect().size.width;
			this->mHeight = this->mSprite->getTextureRect().size.height;

			this->mHorizontalFramesCount = pHorizontalFramesCount;
			this->mVerticalFramesCount   = pVerticalFramesCount;

			/**
			 *
			 * We must remember all coordinates of each frame
			 * for quick get x and y of it.
			 *
			 */

			this->mFramesCoordinatesX = new int[this->mVerticalFramesCount];
			this->mFramesCoordinatesY = new int[this->mHorizontalFramesCount];

			int counter = 0;

			for(int i = 0; i < this->mVerticalFramesCount; i++)
			{
				for(int j = 0; j < this->mHorizontalFramesCount; j++, counter++)
				{
					this->mFramesCoordinatesX[counter] = j * (this->mWidth / this->mHorizontalFramesCount);
					this->mFramesCoordinatesY[counter] = i * (this->mHeight / this->mVerticalFramesCount);
				}
			}

			/**
			 *
			 * Setting zero frame
			 *
			 */

			this->setCurrentFrameIndex(0);
		}

		CCSprite* sprite()
		{
			return this->mSprite;
		}

		int getCurrentFrameIndex()
		{
			return this->mCurrentFrameIndex;
		}

		void setCurrentFrameIndex(int pIndex)
		{
			if(pIndex < this->mHorizontalFramesCount * this->mVerticalFramesCount && pIndex >= 0)
			{
				this->mSprite->setTextureRect(CCRectMake(this->mFramesCoordinatesX[pIndex], this->mFramesCoordinatesY[pIndex], this->mWidth / this->mHorizontalFramesCount, this->mHeight / this->mVerticalFramesCount));

				this->mCurrentFrameIndex = pIndex;
			}
			else
			{
				this->setCurrentFrameIndex(0);
			}
		}

};