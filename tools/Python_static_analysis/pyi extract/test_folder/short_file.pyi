class _TensorBase(object):
    requires_grad: _bool
    shape: Size
    data: Tensor
    names: List[str]
    device: _device
    dtype: _dtype
    layout: _layout
    real: Tensor
    imag: Tensor
    _version: _bool
    def __abs__(self) -> Tensor: ...
    def __add__(self, other: Any) -> Tensor: ...
    def __and__(self, other: Tensor) -> Tensor: ...
    # def __as__(self) -> None: ...
    def fractional_max_pool3d_with_indices(input: Tensor, kernel_size: _size, output_size: Optional[_size] = ...,
                                       output_ratio: Optional[_ratio_any_t] = ..., return_indices: bool = ...,
                                       _random_samples: Optional[Tensor] = ...) -> Tuple[Tensor, Tensor]: ...

def sigmoid(input: Any): ...