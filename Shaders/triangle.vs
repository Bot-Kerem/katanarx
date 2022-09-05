#version 460 core

vec2 vertices[3] = vec2[](
    vec2(0.0f, 0.5f),
    vec2(0.5f, -0.5f),
    vec2(-0.5f, -0.5f)
);
vec3 colors[3] = vec3[](
    vec3(0, 0, 1), // blue
    vec3(0, 1, 0), // green
    vec3(1, 0, 0)  // red
);

out vec3 Color;

uniform mat4 view;
uniform mat4 perspective;

void main(){
    gl_Position = perspective * view * vec4(vertices[gl_VertexID], 0.0f, 1.0f);
    Color = colors[gl_VertexID];
}