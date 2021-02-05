#pragma once

#include <string>
#include "FullscreenShader.hpp"

class Camera;
struct SdfRenderer_Params;

class SdfRenderer {
public:
	SdfRenderer();
	~SdfRenderer() = default;

	// Creates and compiles a shader that will render the scene. Takes some glsl source code implementing a "float SDF(vec3 p)" function
	void setScene(const std::string& sceneSrc);
	void render(const Camera& camera, const SdfRenderer_Params& params);

private:
	FullscreenShader _shader;
	std::string _rendererSrc;
};