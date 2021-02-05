#include "SdfRenderer.hpp"

#include "Utility/Time.hpp"
#include "Utility/File.hpp"
#include "Camera/Camera.hpp"
#include "SdfRenderer_Params.hpp"
#include "Utility/File.hpp"

SdfRenderer::SdfRenderer()
	: _rendererSrc(MyFile::LoadToString("shaders/rendering/SDF_Test1.fs.glsl")) // We don't provide choice for the rendering code used because setting the uniforms in render() depends on the render code
{
	setScene(MyFile::LoadToString("shaders/simulation/SDF_Test1.fs.glsl"));
}

void SdfRenderer::setScene(const std::string& sceneSrc) {
	_shader.compile("#version 330\n" + sceneSrc + _rendererSrc);
}

void SdfRenderer::render(const Camera& camera, const SdfRenderer_Params& params) {
	_shader.get().bind();
	_shader.get().setUniformValue("iTime", Time::Elapsed() / 1000.f); // TODO it is more the responsibility of the scene than the renderer to know whether this kind of uniform is required
	// Camera settings
	_shader.get().setUniformValue("u_AspectRatio", 1.0f); // TODO set me properly
	_shader.get().setUniformValue("u_CamX", camera.xAxis());
	_shader.get().setUniformValue("u_CamY", camera.yAxis());
	_shader.get().setUniformValue("u_CamZ", camera.zAxis());
	_shader.get().setUniformValue("u_CamPos", camera.position());
	_shader.get().setUniformValue("u_FocalLength", camera.focalLength());
	// Rendering params
	_shader.get().setUniformValue("u_AbsorptionCoefficient", params.absorptionCoefficient);
	_shader.get().setUniformValue("u_AbsorptionCutoff", params.absorptionCutoff);
	_shader.get().setUniformValue("u_MarchMultiplier", params.marchMultiplier);
	_shader.get().setUniformValue("u_MaxVolumeMarchSteps", params.maxVolumeMarchSteps);
	_shader.get().setUniformValue("u_MaxVolumeLightMarchSteps", params.maxVolumeLightMarchSteps);
	_shader.get().setUniformValue("u_MaxSdfSphereSteps", params.maxSdfSphereSteps);
	_shader.get().setUniformValue("u_MaxOpaqueShadowMarchSteps", params.maxOpaqueShadowMarchSteps);
	//
	_shader.draw();
}