#pragma once

namespace yz
{
class GraphicsFeatures
{
public:
	void Init();

	bool HasDXT1() const;
	bool HasS3TC() const;
	bool HasPVRTC() const;
	bool HasETC1() const;
	bool HasETC2() const;
	bool HasATITC() const;

private:
	bool m_inited {false};
	bool m_dxt1 {false};
	bool m_s3tc {false};
	bool m_pvrtc {false};
	bool m_etc1 {false};
	bool m_etc2 {false};
	bool m_atitc {false};
};
}