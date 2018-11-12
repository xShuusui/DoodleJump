#version 330 core

in vec2 pass_textureCoords;

out vec4 color;

uniform sampler2D textureSample;

void main(void) {
    color = texture(textureSample, pass_textureCoords);
}