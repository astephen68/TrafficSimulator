#version 330 core
layout(location=0) in vec3 pos;
layout(location=1) in vec3 color;
out vec3 inColor;
layout (location=2) in vec2 offset;
uniform mat4 projection;
uniform mat4 world2;
void main(){
  gl_Position=vec4(pos.x+offset.x,offset.y+pos.y,pos.z,1.0f)*world2*projection;
  inColor=color;
}
