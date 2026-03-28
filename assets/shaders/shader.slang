struct VertexInput
{
    float2 position;
    float3 color;
};

struct FragmentInput
{
    float4 position : SV_Position;
    float3 color;
};

struct UniformBuffer
{
    float4x4 model;
    float4x4 view;
    float4x4 projection;
};
ConstantBuffer<UniformBuffer> ubo;

[shader("vertex")]
FragmentInput vertMain(VertexInput input)
{
    FragmentInput output;
    output.position = mul(ubo.projection, mul(ubo.view, mul(ubo.model, float4(input.position, 0.0, 1.0))));
    output.color = input.color;
    return output;
}

[shader("fragment")]
float4 fragMain(FragmentInput input) : SV_TARGET
{
    return float4(input.color, 1.0);
}