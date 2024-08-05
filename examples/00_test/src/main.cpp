#include "viridis_runtime/app/application_builder.hpp"
#include "viridis_runtime/renderer/opengl/opengl_renderer_bundle.hpp"

using namespace viridis;

int main() {
    auto renderer = OpenglRendererBundle()
        .with_version(3, 2);
    auto app = ApplicationBuilder { renderer }
        .with_title("Test Application")
        .with_window_size({ 1280, 720 })
        .with_window_kind(WindowKind::Resizable)
        .limit_framerate(60)
        .build();

    app->run();
}
