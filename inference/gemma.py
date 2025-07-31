import torch
from transformers import AutoTokenizer, AutoModelForCausalLM, pipeline

# # Optional: force offline mode (will raise an error if files are missing)
# from huggingface_hub import hf_hub_download
# from transformers.utils import is_offline_mode, set_offline_mode

# # Force offline mode (skip this if you want fallback to online)
# set_offline_mode()

# Define the model name (cached)
model_name = "google/gemma-3-4b-it"

# Load tokenizer and model from local cache
print("Loading from local cache...")
tokenizer = AutoTokenizer.from_pretrained(model_name, local_files_only=True)
model = AutoModelForCausalLM.from_pretrained(
    model_name,
    local_files_only=True,
    torch_dtype=torch.float16 if torch.xpu.is_available() else torch.float32,
    device_map="auto"
)

# Set up pipeline
text_gen = pipeline(
    "text-generation",
    model=model,
    tokenizer=tokenizer
  
)

# Run inference
prompt = "Hi"
print(f"\nPrompt:\n{prompt}")
output = text_gen(prompt, max_new_tokens=100, do_sample=True, temperature=0.7)
print(f"\nGenerated:\n{output[0]['generated_text']}")
