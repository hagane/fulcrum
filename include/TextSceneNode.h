#include <string>
#include "export.h"
#include "OpenGL.h"
#include "SceneNode.h"
#include "Font.h"

namespace FGF
{
	class EXPORT TextSceneNode: public SceneNode
	{
	public:
		TextSceneNode(SceneNode* parent, Font* f);
		virtual ~TextSceneNode();
		virtual void setString(std::wstring s);
		virtual void Render();
	private:
		std::wstring str;
		Font* font;
	};
}
