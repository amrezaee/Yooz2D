#include <Graphics/yzGraphicsFeatures.hpp>

#include <yzDeps.hpp>

namespace yz
{
void GraphicsFeatures::Init() 
{
	if(m_inited) return;

	m_s3tc = GLAD_GL_EXT_texture_compression_s3tc;
	
	m_dxt1 = m_s3tc || GLAD_GL_EXT_texture_compression_dxt1;

	m_pvrtc = GLAD_GL_IMG_texture_compression_pvrtc;

	m_etc1 = GLAD_GL_OES_compressed_ETC1_RGB8_texture;

	m_etc2 = GLAD_GL_ARB_ES3_compatibility;

	m_atitc = GLAD_GL_AMD_compressed_ATC_texture;

	m_inited = true;
}

bool GraphicsFeatures::HasDXT1() const { return m_dxt1; }
bool GraphicsFeatures::HasS3TC() const { return m_s3tc; }
bool GraphicsFeatures::HasPVRTC() const { return m_pvrtc; }
bool GraphicsFeatures::HasETC1() const { return m_etc1; }
bool GraphicsFeatures::HasETC2() const { return m_etc2; }
bool GraphicsFeatures::HasATITC() const { return m_atitc; }

}
